	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r2, #0
	ldr r6, _081E49C4 @ =0x03003584
	movs r0, #0xb3
	lsls r0, r0, #4
	adds r7, r4, r0
_081E49B6:
	cmp r2, #3
	bne _081E49C8
	ldr r0, [r6]
	movs r3, #0xa5
	lsls r3, r3, #7
	b _081E49CC
	.align 2, 0
_081E49C4: .4byte 0x03003584
_081E49C8:
	ldr r0, [r6]
	ldr r3, _081E4A4C @ =0x00005260
_081E49CC:
	adds r1, r0, r3
	lsls r0, r2, #5
	adds r5, r2, #1
	adds r2, r1, #0
	adds r1, r0, r7
	movs r3, #0xf
_081E49D8:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, #2
	adds r1, #2
	subs r3, #1
	cmp r3, #0
	bge _081E49D8
	adds r2, r5, #0
	cmp r2, #3
	ble _081E49B6
	movs r2, #0
	ldr r1, _081E4A50 @ =0x00000B62
	adds r0, r4, r1
	ldrh r1, [r0]
	ldr r3, _081E4A54 @ =0x00000B52
	adds r0, r4, r3
	strh r1, [r0]
	ldr r1, _081E4A58 @ =0x00000B64
	adds r0, r4, r1
	ldrh r1, [r0]
	adds r3, #2
	adds r0, r4, r3
	strh r1, [r0]
	ldr r1, _081E4A5C @ =0x00000B66
	adds r0, r4, r1
	ldrh r1, [r0]
	adds r3, #2
	adds r0, r4, r3
	strh r1, [r0]
	movs r1, #0xe6
	lsls r1, r1, #3
	adds r0, r4, r1
	subs r3, #0x26
	adds r1, r4, r3
	str r1, [r0]
	movs r3, #0xf2
	lsls r3, r3, #3
	adds r0, r4, r3
	str r1, [r0]
	movs r1, #0xce
	lsls r1, r1, #3
	adds r0, r4, r1
	movs r3, #0xb7
	lsls r3, r3, #4
	adds r1, r4, r3
	str r1, [r0]
	movs r3, #0xda
	lsls r3, r3, #3
	adds r0, r4, r3
	str r1, [r0]
	movs r1, #0xbb
	lsls r1, r1, #4
	adds r0, r4, r1
	strh r2, [r0]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E4A4C: .4byte 0x00005260
_081E4A50: .4byte 0x00000B62
_081E4A54: .4byte 0x00000B52
_081E4A58: .4byte 0x00000B64
_081E4A5C: .4byte 0x00000B66
