	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r0, _080A11A4 @ =0x03002C40
	ldr r0, [r0]
	cmp r0, #0
	bne _080A11B2
	movs r0, #8
	movs r1, #0x20
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A11B0
	ldr r1, _080A11A8 @ =EntityBA36_Update
	ldr r2, _080A11AC @ =EntityBA36_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl EntityBA36_Init
	cmp r0, #0
	bge _080A11B0
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A11B2
	.align 2, 0
_080A11A4: .4byte 0x03002C40
_080A11A8: .4byte EntityBA36_Update
_080A11AC: .4byte EntityBA36_Destroy
_080A11B0:
	adds r0, r4, #0
_080A11B2:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
