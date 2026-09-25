	push {lr}
	adds r2, r0, #0
	ldrh r0, [r2, #0x38]
	adds r0, #1
	strh r0, [r2, #0x38]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bhi _080AC48A
	ldr r1, [r2, #0x30]
	adds r0, r2, #0
	movs r2, #3
	bl FUN_0822dafc
	b _080AC4B0
_080AC48A:
	cmp r0, #7
	bhi _080AC49A
	ldr r1, [r2, #0x30]
	adds r0, r2, #0
	movs r2, #2
	bl FUN_0822dafc
	b _080AC4B0
_080AC49A:
	ldrh r1, [r2, #0x3a]
	cmp r0, r1
	bhs _080AC4AA
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	b _080AC4B0
_080AC4AA:
	adds r0, r2, #0
	bl FUN_080ac3d4
_080AC4B0:
	pop {r0}
	bx r0
