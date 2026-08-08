	push {r4, r5, r6, lr}
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	ldr r0, _080EEAF4 @ =0x03002C5C
	ldr r0, [r0]
	cmp r0, #0
	bne _080EEB02
	movs r1, #0xa0
	lsls r1, r1, #2
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080EEB00
	ldr r1, _080EEAF8 @ =FUN_080eea24
	ldr r2, _080EEAFC @ =0x080EEA65
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r5, #0
	bl FUN_080eea84
	cmp r0, #0
	bge _080EEB00
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080EEB02
	.align 2, 0
_080EEAF4: .4byte 0x03002C5C
_080EEAF8: .4byte FUN_080eea24
_080EEAFC: .4byte 0x080EEA65
_080EEB00:
	adds r0, r4, #0
_080EEB02:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
