	push {r4, r5, r6, r7, lr}
	ldr r0, _080E0284 @ =0x0300017C
	ldr r0, [r0]
	cmp r0, #0
	beq _080E027C
	movs r7, #2
	movs r1, #0xf5
	lsls r1, r1, #1
	adds r3, r0, r1
	adds r2, r0, #0
	ldr r0, _080E0288 @ =0x00000BEC
	adds r5, r2, r0
	movs r6, #0xf7
	lsls r6, r6, #1
	movs r4, #0xda
	lsls r4, r4, #1
_080E0268:
	ldrb r1, [r3]
	cmp r1, #1
	bne _080E0274
	strb r7, [r3]
	adds r0, r2, r6
	strb r1, [r0]
_080E0274:
	adds r3, r3, r4
	adds r2, r2, r4
	cmp r2, r5
	ble _080E0268
_080E027C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080E0284: .4byte 0x0300017C
_080E0288: .4byte 0x00000BEC
