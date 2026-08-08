	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08238E6C @ =0x030046D4
	ldr r1, [r0]
	cmp r1, #0
	bge _08238E74
	movs r0, #3
	rsbs r0, r0, #0
	cmp r1, r0
	ble _08238E74
	ldr r2, _08238E70 @ =0x0000FFFF
	adds r0, r2, #0
	strh r0, [r4]
	strh r0, [r4, #2]
	strh r0, [r4, #4]
	strh r0, [r4, #6]
	adds r0, r1, #0
	b _08238EA6
	.align 2, 0
_08238E6C: .4byte 0x030046D4
_08238E70: .4byte 0x0000FFFF
_08238E74:
	bl FUN_0823860c
	ldr r2, _08238EAC @ =0x030046F0
	ldr r0, _08238EB0 @ =0x03000830
	ldr r1, [r0]
	lsls r1, r1, #3
	adds r0, r1, r2
	ldrh r0, [r0]
	strh r0, [r4]
	adds r0, r2, #2
	adds r0, r1, r0
	ldrh r0, [r0]
	strh r0, [r4, #2]
	adds r0, r2, #4
	adds r0, r1, r0
	ldrh r0, [r0]
	strh r0, [r4, #4]
	adds r2, #6
	adds r1, r1, r2
	ldrh r0, [r1]
	strh r0, [r4, #6]
	bl FUN_08238618
	ldr r0, _08238EB4 @ =0x030046CC
	ldr r0, [r0]
_08238EA6:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08238EAC: .4byte 0x030046F0
_08238EB0: .4byte 0x03000830
_08238EB4: .4byte 0x030046CC
