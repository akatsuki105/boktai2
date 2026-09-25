	push {r4, lr}
	ldr r0, _080DB554 @ =0x03000160
	ldr r0, [r0]
	cmp r0, #0
	bne _080DB566
	ldr r1, _080DB558 @ =0x0000055C
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080DB564
	ldr r1, _080DB55C @ =Entity080db520_Update
	ldr r2, _080DB560 @ =Entity080db520_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity080db520_Init
	cmp r0, #0
	bge _080DB564
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080DB566
	.align 2, 0
_080DB554: .4byte 0x03000160
_080DB558: .4byte 0x0000055C
_080DB55C: .4byte Entity080db520_Update
_080DB560: .4byte Entity080db520_Destroy
_080DB564:
	adds r0, r4, #0
_080DB566:
	pop {r4}
	pop {r1}
	bx r1
