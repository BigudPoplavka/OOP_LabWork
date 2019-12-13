#pragma once
class ILoadable
{
public:
	virtual void Load(int weight) = 0;
	virtual ~ILoadable() {}
};