	push {r4, lr}
	ldr r0, _080ACD84 @ =0x03002C54
	ldr r0, [r0]
	cmp r0, #0
	bne _080ACD92
	movs r1, #0xce
	lsls r1, r1, #1
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080ACD90
	ldr r1, _080ACD88 @ =Entity080acd4c_Update
	ldr r2, _080ACD8C @ =Entity080acd4c_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity080acd4c_Init
	cmp r0, #0
	bge _080ACD90
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080ACD92
	.align 2, 0
_080ACD84: .4byte 0x03002C54
_080ACD88: .4byte Entity080acd4c_Update
_080ACD8C: .4byte Entity080acd4c_Destroy
_080ACD90:
	adds r0, r4, #0
_080ACD92:
	pop {r4}
	pop {r1}
	bx r1
