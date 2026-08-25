	push {r4, lr}
	movs r0, #9
	movs r1, #0x84
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080AB010
	ldr r1, _080AB008 @ =EntityC438_Update
	ldr r2, _080AB00C @ =EntityC438_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl EntityC438_Init
	cmp r0, #0
	bge _080AB010
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080AB012
	.align 2, 0
_080AB008: .4byte EntityC438_Update
_080AB00C: .4byte EntityC438_Destroy
_080AB010:
	adds r0, r4, #0
_080AB012:
	pop {r4}
	pop {r1}
	bx r1
