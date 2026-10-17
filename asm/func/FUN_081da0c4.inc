	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _081DA0FC @ =0x0000029D
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _081DA100 @ =0x00000286
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r1, [r0]
	ldr r0, _081DA104 @ =0x030046A0
	ldr r1, [r0]
	subs r2, #0x48
	adds r0, r1, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	ble _081DA10C
	ldr r0, _081DA108 @ =0x00000289
	adds r1, r4, r0
	movs r0, #3
	b _081DA128
	.align 2, 0
_081DA0FC: .4byte 0x0000029D
_081DA100: .4byte 0x00000286
_081DA104: .4byte 0x030046A0
_081DA108: .4byte 0x00000289
_081DA10C:
	movs r2, #0x8e
	lsls r2, r2, #2
	adds r0, r1, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq _081DA122
	adds r2, #0x51
	adds r1, r4, r2
	movs r0, #2
	b _081DA128
_081DA122:
	ldr r0, _081DA144 @ =0x00000289
	adds r1, r4, r0
	movs r0, #1
_081DA128:
	strb r0, [r1]
	ldr r2, _081DA148 @ =0x0000028A
	adds r1, r4, r2
	movs r0, #4
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_081da038
	adds r0, r4, #0
	bl FUN_081da074
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081DA144: .4byte 0x00000289
_081DA148: .4byte 0x0000028A
