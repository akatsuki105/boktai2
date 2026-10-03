	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, _080ACC00 @ =0x000008E4
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080ACC0C
	strh r5, [r4, #0x18]
	ldr r1, _080ACC04 @ =EntityB6FF_Update
	ldr r2, _080ACC08 @ =EntityB6FF_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl EntityB6FF_Init
	cmp r0, #0
	bge _080ACC0C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080ACC0E
	.align 2, 0
_080ACC00: .4byte 0x000008E4
_080ACC04: .4byte EntityB6FF_Update
_080ACC08: .4byte EntityB6FF_Destroy
_080ACC0C:
	adds r0, r4, #0
_080ACC0E:
	pop {r4, r5}
	pop {r1}
	bx r1
