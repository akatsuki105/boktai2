	push {r4, lr}
	adds r2, r0, #0
	ldr r1, _08196AE4 @ =0x00000CEC
	adds r0, r2, r1
	ldr r0, [r0]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _08196AFE
	movs r4, #0x8a
	lsls r4, r4, #3
	adds r3, r2, r4
	ldr r1, _08196AE8 @ =0x00000ACA
	adds r0, r2, r1
	ldr r1, [r3]
	ldrh r0, [r0]
	cmp r1, r0
	blt _08196AF4
	ldr r4, _08196AEC @ =0x00000C4C
	adds r1, r2, r4
	ldr r0, _08196AF0 @ =FUN_08196b08
	str r0, [r1]
	b _08196AFE
	.align 2, 0
_08196AE4: .4byte 0x00000CEC
_08196AE8: .4byte 0x00000ACA
_08196AEC: .4byte 0x00000C4C
_08196AF0: .4byte FUN_08196b08
_08196AF4:
	ldr r4, _08196B04 @ =0x00000ACC
	adds r0, r2, r4
	ldrh r0, [r0]
	adds r0, r1, r0
	str r0, [r3]
_08196AFE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08196B04: .4byte 0x00000ACC
