	push {lr}
	adds r2, r0, #0
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _080CE554
	movs r2, #0
	b _080CE576
_080CE554:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _080CE560
	movs r2, #1
	b _080CE576
_080CE560:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _080CE56C
	movs r2, #2
	b _080CE576
_080CE56C:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _080CE596
	movs r2, #3
_080CE576:
	movs r0, #7
	ands r0, r1
	cmp r0, #0
	beq _080CE596
	ldr r1, _080CE59C @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _080CE596
	ldr r0, [r1, #0x1c]
	cmp r0, #1
	bne _080CE596
	adds r0, r1, #0
	bl Player_UpdateBloodSword
_080CE596:
	pop {r0}
	bx r0
	.align 2, 0
_080CE59C: .4byte 0x03002BE0
