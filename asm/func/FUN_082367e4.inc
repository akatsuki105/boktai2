	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldrh r0, [r5]
	ldrh r1, [r4]
	subs r0, r0, r1
	lsls r1, r0, #0x10
	asrs r0, r1, #0x10
	cmp r0, #0
	blt _082367FC
	asrs r0, r1, #0x11
	b _08236806
_082367FC:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
_08236806:
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	ldrh r0, [r4]
	ldrh r1, [r5]
	adds r0, r0, r1
	lsls r1, r0, #0x10
	asrs r0, r1, #0x10
	cmp r0, #0
	blt _0823681C
	asrs r0, r1, #0x11
	b _08236826
_0823681C:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
_08236826:
	strh r0, [r2, #0x24]
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge _08236832
	rsbs r0, r0, #0
_08236832:
	strh r0, [r2, #0x1c]
	ldrh r1, [r5, #2]
	ldrh r0, [r4, #2]
	subs r0, r1, r0
	lsls r3, r0, #0x10
	asrs r0, r3, #0x10
	cmp r0, #0
	blt _08236846
	asrs r0, r3, #0x11
	b _08236850
_08236846:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
_08236850:
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	ldrh r0, [r4, #2]
	adds r0, r1, r0
	lsls r1, r0, #0x10
	asrs r0, r1, #0x10
	cmp r0, #0
	blt _08236864
	asrs r0, r1, #0x11
	b _0823686E
_08236864:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
_0823686E:
	strh r0, [r2, #0x26]
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge _0823687A
	rsbs r0, r0, #0
_0823687A:
	strh r0, [r2, #0x1e]
	ldrh r1, [r5, #4]
	ldrh r0, [r4, #4]
	subs r0, r1, r0
	lsls r3, r0, #0x10
	asrs r0, r3, #0x10
	cmp r0, #0
	blt _0823688E
	asrs r0, r3, #0x11
	b _08236898
_0823688E:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
_08236898:
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	ldrh r0, [r4, #4]
	adds r0, r1, r0
	lsls r1, r0, #0x10
	asrs r0, r1, #0x10
	cmp r0, #0
	blt _082368AC
	asrs r0, r1, #0x11
	b _082368B6
_082368AC:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
_082368B6:
	movs r1, #0
	strh r0, [r2, #0x28]
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge _082368C4
	rsbs r0, r0, #0
_082368C4:
	strh r0, [r2, #0x20]
	strh r1, [r2, #0x14]
	strh r1, [r2, #0x16]
	strh r1, [r2, #0x18]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
