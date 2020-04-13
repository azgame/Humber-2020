#include "LoadOBJModel.h"

LoadOBJModel::LoadOBJModel(){
	currentMaterial = Material();
	vertices.reserve(200);
	normals.reserve(200);
	textureCoords.reserve(200);
	indices.reserve(200);
	normalIndices.reserve(200);
	textureIndices.reserve(200);
	meshVertices.reserve(200);
	subMeshes.reserve(10);
	box = BoundingBox();
}

LoadOBJModel::~LoadOBJModel(){
	OnDestroy();
}

void LoadOBJModel::LoadModel(const std::string& objFilePath_, const std::string& mtlFilePath_){
	LoadMaterialLibrary(mtlFilePath_);
	LoadModel(objFilePath_);
}

void LoadOBJModel::LoadModel(const std::string& filePath_){
	std::ifstream in(filePath_.c_str(), std::ios::in);
	if (!in) {
		Debug::Error("Object file cannot be opened." + filePath_, "LoadOBJModel.cpp", __LINE__);
		return;
	}
	std::string line;
	while (std::getline(in, line)) {
		//VERTEX DATA
		if (line.substr(0, 2) == "v ") {
			std::stringstream v(line.substr(2));
			float x, y, z;
			v >> x >> y >> z;

			if (x > maxX) {
				maxX = x;
			}
			if (y > maxY) {
				maxY = y;
			}
			if (z > maxZ) {
				maxZ = z;
			}
			if (x < minX) {
				minX = x;
			}
			if (y < maxY) {
				minY = y;
			}
			if (z < maxZ) {
				minZ = z;
			}
			box.maxVert.x = maxX;
			box.maxVert.y = maxY;
			box.maxVert.z = maxZ;
			box.minVert.x = minX;
			box.minVert.y = minY;
			box.minVert.z = minZ;
			vertices.push_back(glm::vec3(x, y, z));
		}
		//NORMAL DATA
		if (line.substr(0, 3) == "vn ") {
			std::stringstream vn(line.substr(2));
			float x, y, z;
			
			vn >> x >> y >> z;
			normals.push_back(glm::vec3(x, y, z));
		}
		//TEXTURE DATA
		if (line.substr(0, 3) == "vt ") {
			std::stringstream vt(line.substr(2));
			float u, v;
			vt >> u >> v;

			textureCoords.push_back(glm::vec2(u, v));
		}
		//FACE DATA
		/*if (line.substr(0, 2) == "f ") {
			std::stringstream v(line.substr(2));
			
			int a, b, c, d, e, f, g, h, i;
			
			v >> a >> b >> c >> d >> e >> f >> g >> h >> i;
			std::cout << "Face 1: " << a << " " << b << " " << c << " Face 2: " << d << " " << e << " " << f << " Face 3: " << g << " " << h << " " << i << std::endl;
			indices.push_back(a);
			indices.push_back(b);
			indices.push_back(c);

			textureIndices.push_back(d);
			textureIndices.push_back(e);
			textureIndices.push_back(f);

			normalIndices.push_back(g);
			normalIndices.push_back(h);
			normalIndices.push_back(i);
		}*/
		if (line.substr(0, 2) == "f ") {
			std::string data = line.substr(2);
			int endPosition = 0;
			while ((endPosition = data.find(' ')) != std::string::npos) {
				std::string chunk = data.substr(0, endPosition);
				int subEndPos = 0;
				int vector = 0;


				for (int i = 0; i < 3; i++) {
					int push;
					if ((subEndPos = chunk.find('/')) != std::string::npos) {

						push = std::stoi(chunk.substr(0, subEndPos));

						chunk.erase(0, subEndPos + 1);
					}
					else {
						push = std::stoi(chunk);
					}

					push--;

					switch (i) {
					default:
					case 0:
						indices.push_back(push);
						break;
					case 1:
						textureIndices.push_back(push);
						break;
					case 2:
						normalIndices.push_back(push);
						break;
					}
				}
				vector = 0;
				data.erase(0, endPosition + 1);
			}
		}
		//New Mesh
		else if (line.substr(0, 7) == "usemtl ") {
			if (indices.size() > 0) {
				PostProcessing();
			}
			LoadMaterial(line.substr(7));
		}
	}
	PostProcessing();
}

std::vector<Vertex> LoadOBJModel::GetVerts(){
	return meshVertices;
}

std::vector<int> LoadOBJModel::GetIndicies() {
	return indices;
}

std::vector<SubMesh> LoadOBJModel::GetSubMeshes(){
	return subMeshes;
}

BoundingBox LoadOBJModel::GetBoundingBox()
{
	return box;
}

void LoadOBJModel::OnDestroy(){
	vertices.clear();
	normals.clear();
	textureCoords.clear();
	indices.clear();
	normalIndices.clear();
	textureIndices.clear();
	meshVertices.clear();
	subMeshes.clear();
}

void LoadOBJModel::PostProcessing(){
	for (int i = 0; i < indices.size(); i++) {
		Vertex vert;
		vert.position = vertices[indices[i]];
		vert.normal = normals[normalIndices[i]];
		vert.texCoords = textureCoords[textureIndices[i]];
		meshVertices.push_back(vert);
	}

	SubMesh subMesh;
	subMesh.vertexList = meshVertices;
	subMesh.meshIndices = indices;
	subMesh.material = currentMaterial;

	subMeshes.push_back(subMesh);

	indices.clear();
	normalIndices.clear();
	textureIndices.clear();
	meshVertices.clear();
	currentMaterial = Material();
}

void LoadOBJModel::LoadMaterial(const std::string& matName_)
{
	currentMaterial = MaterialHandler::GetInstance()->GetMaterial(matName_);
}


void LoadOBJModel::LoadMaterialLibrary(const std::string& matFilePath_)
{
	MaterialLoader::LoadMaterial(matFilePath_);
}

