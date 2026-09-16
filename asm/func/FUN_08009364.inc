	push {lr}
	adds r3, r0, #0
	ldr r2, [r3, #0x24]
	ldr r1, _0800938C @ =0x0000186C
	ldr r0, [r2, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _08009390
	movs r1, #0xe0
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08009390
	movs r0, #0x19
	ldrsb r0, [r3, r0]
	cmp r0, #0
	bge _08009390
	movs r0, #1
	b _08009392
	.align 2, 0
_0800938C: .4byte 0x0000186C
_08009390:
	movs r0, #0
_08009392:
	pop {r1}
	bx r1
	.align 2, 0
