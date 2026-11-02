	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _081473C4 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081473C8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081473CA
	.align 2, 0
_081473C4: .4byte 0x0000046D
_081473C8:
	movs r0, #0
_081473CA:
	cmp r0, #0
	beq _08147406
	adds r0, r4, #0
	bl FUN_081489a0
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081473EC
	ldrb r0, [r4, #5]
	bl FUN_08148750
	adds r2, r0, #0
	adds r0, r4, #0
	movs r1, #0xf
	bl FUN_080efb60
	b _081473FC
_081473EC:
	ldrb r0, [r4, #5]
	bl FUN_08148750
	adds r2, r0, #0
	adds r0, r4, #0
	movs r1, #0x10
	bl FUN_080efb60
_081473FC:
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r4, r1
	bl ParticleShadow_Hide
_08147406:
	ldr r1, _08147420 @ =0x0000046E
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08147418
	ldr r0, _08147424 @ =0x0000046B
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_08147418:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08147420: .4byte 0x0000046E
_08147424: .4byte 0x0000046B
