	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r5, r2, #0
	lsls r7, r1, #2
	movs r2, #0
	ldr r0, _081E020C @ =0x000003E7
	cmp r5, r0
	ble _081E017E
	ldr r1, _081E0210 @ =0xFFFFFC18
_081E0176:
	adds r2, #1
	adds r5, r5, r1
	cmp r5, r0
	bgt _081E0176
_081E017E:
	lsls r4, r7, #1
	adds r0, r4, r7
	lsls r0, r0, #5
	movs r1, #0x9c
	lsls r1, r1, #1
	adds r0, r0, r1
	adds r0, r6, r0
	movs r3, #0xc6
	lsls r3, r3, #2
	adds r1, r6, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl MainSprite_LoadPose
	movs r2, #0
	cmp r5, #0x63
	ble _081E01A8
_081E01A0:
	adds r2, #1
	subs r5, #0x64
	cmp r5, #0x63
	bgt _081E01A0
_081E01A8:
	adds r0, r4, r7
	lsls r0, r0, #5
	adds r0, #0xd8
	adds r0, r6, r0
	movs r3, #0xc6
	lsls r3, r3, #2
	adds r1, r6, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl MainSprite_LoadPose
	movs r2, #0
	cmp r5, #9
	ble _081E01CC
_081E01C4:
	adds r2, #1
	subs r5, #0xa
	cmp r5, #9
	bgt _081E01C4
_081E01CC:
	adds r0, r4, r7
	lsls r0, r0, #5
	adds r0, #0x78
	adds r0, r6, r0
	movs r3, #0xc6
	lsls r3, r3, #2
	adds r1, r6, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl MainSprite_LoadPose
	movs r2, #0
	cmp r5, #0
	ble _081E01F0
_081E01E8:
	adds r2, #1
	subs r5, #1
	cmp r5, #0
	bgt _081E01E8
_081E01F0:
	adds r0, r4, r7
	lsls r0, r0, #5
	adds r0, #0x18
	adds r0, r6, r0
	movs r3, #0xc6
	lsls r3, r3, #2
	adds r1, r6, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl MainSprite_LoadPose
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E020C: .4byte 0x000003E7
_081E0210: .4byte 0xFFFFFC18
