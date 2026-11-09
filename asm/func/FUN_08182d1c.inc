	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _08182D3C @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08182D40
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08182D42
	.align 2, 0
_08182D3C: .4byte 0x0000046C
_08182D40:
	movs r0, #0
_08182D42:
	cmp r0, #0
	beq _08182D7A
	ldr r4, _08182DC4 @ =FUN_0817fd8c
	movs r3, #0x28
	ldr r0, _08182DC8 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08182DCC @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	adds r1, #0x25
	adds r0, r5, r1
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
	movs r2, #8
	ldr r0, _08182DD0 @ =0x00000898
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_08182D7A:
	ldr r2, _08182DD4 @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	cmp r0, #0x1e
	ble _08182DDC
	adds r0, r5, #0
	bl FUN_0817ba7c
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08182DB4
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r5, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r5, r2
	strb r1, [r0]
	adds r2, #0x1a
	adds r0, r5, r2
	str r1, [r0]
	ldr r0, _08182DD8 @ =0x0000046C
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_08182DB4:
	ldr r1, _08182DD0 @ =0x00000898
	adds r2, r6, r1
	movs r1, #9
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _08182DE0
	.align 2, 0
_08182DC4: .4byte FUN_0817fd8c
_08182DC8: .4byte 0x0000046D
_08182DCC: .4byte 0x0000046B
_08182DD0: .4byte 0x00000898
_08182DD4: .4byte 0x00000484
_08182DD8: .4byte 0x0000046C
_08182DDC:
	adds r0, #1
	str r0, [r1]
_08182DE0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
