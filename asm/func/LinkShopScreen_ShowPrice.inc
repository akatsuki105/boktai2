	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r7, #0
	ldr r1, _081E4878 @ =0x000015E2
	adds r0, r5, r1
	ldrh r4, [r0]
	movs r6, #0
	movs r2, #0
	ldr r0, _081E487C @ =0x000003E7
	cmp r4, r0
	ble _081E4858
	ldr r1, _081E4880 @ =0xFFFFFC18
_081E4850:
	adds r2, #1
	adds r4, r4, r1
	cmp r4, r0
	bgt _081E4850
_081E4858:
	cmp r2, r7
	bgt _081E4860
	cmp r6, #0
	ble _081E4888
_081E4860:
	movs r3, #0xa4
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r3, _081E4884 @ =0x00000AA8
	adds r1, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl MainSprite_LoadPose
	adds r6, #1
	b _081E4896
	.align 2, 0
_081E4878: .4byte 0x000015E2
_081E487C: .4byte 0x000003E7
_081E4880: .4byte 0xFFFFFC18
_081E4884: .4byte 0x00000AA8
_081E4888:
	movs r1, #0xa8
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
_081E4896:
	adds r2, r7, #0
	cmp r4, #0x63
	ble _081E48A4
_081E489C:
	adds r2, #1
	subs r4, #0x64
	cmp r4, #0x63
	bgt _081E489C
_081E48A4:
	cmp r2, r7
	bgt _081E48AC
	cmp r6, #0
	ble _081E48C4
_081E48AC:
	adds r0, r5, #0
	adds r0, #0xe8
	ldr r3, _081E48C0 @ =0x00000AA8
	adds r1, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl MainSprite_LoadPose
	adds r6, #1
	b _081E48D0
	.align 2, 0
_081E48C0: .4byte 0x00000AA8
_081E48C4:
	adds r0, r5, #0
	adds r0, #0xf0
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
_081E48D0:
	adds r2, r7, #0
	cmp r4, #9
	ble _081E48DE
_081E48D6:
	adds r2, #1
	subs r4, #0xa
	cmp r4, #9
	bgt _081E48D6
_081E48DE:
	cmp r2, r7
	bgt _081E48E6
	cmp r6, #0
	ble _081E4900
_081E48E6:
	adds r0, r5, #0
	adds r0, #0x88
	ldr r3, _081E48FC @ =0x00000AA8
	adds r1, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl MainSprite_LoadPose
	adds r6, #1
	b _081E490C
	.align 2, 0
_081E48FC: .4byte 0x00000AA8
_081E4900:
	adds r0, r5, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
_081E490C:
	adds r2, r7, #0
	cmp r4, #0
	ble _081E491A
_081E4912:
	adds r2, #1
	subs r4, #1
	cmp r4, #0
	bgt _081E4912
_081E491A:
	cmp r2, r7
	bgt _081E4922
	cmp r6, #0
	blt _081E4938
_081E4922:
	adds r0, r5, #0
	adds r0, #0x28
	ldr r3, _081E4934 @ =0x00000AA8
	adds r1, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl MainSprite_LoadPose
	b _081E4940
	.align 2, 0
_081E4934: .4byte 0x00000AA8
_081E4938:
	ldr r0, [r5, #0x30]
	movs r1, #1
	orrs r0, r1
	str r0, [r5, #0x30]
_081E4940:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
