	push {r4, r5, lr}
	ldr r5, _080DC484 @ =0x03000168
	ldr r0, [r5]
	cmp r0, #0
	bne _080DC492
	movs r1, #0xb1
	lsls r1, r1, #2
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	str r4, [r5]
	cmp r4, #0
	beq _080DC490
	ldr r1, _080DC488 @ =Entity080dc44c_Update
	ldr r2, _080DC48C @ =Entity080dc44c_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity080dc44c_Init
	cmp r0, #0
	bge _080DC490
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080DC492
	.align 2, 0
_080DC484: .4byte 0x03000168
_080DC488: .4byte Entity080dc44c_Update
_080DC48C: .4byte Entity080dc44c_Destroy
_080DC490:
	adds r0, r4, #0
_080DC492:
	pop {r4, r5}
	pop {r1}
	bx r1
