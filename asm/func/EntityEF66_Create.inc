	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080A169C @ =0x03000148
	ldr r0, [r0]
	cmp r0, #0
	bne _080A16AA
	movs r0, #9
	movs r1, #0x30
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A16A8
	ldr r1, _080A16A0 @ =EntityEF66_Update
	ldr r2, _080A16A4 @ =EntityEF66_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl EntityEF66_Init
	cmp r0, #0
	bge _080A16A8
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A16AA
	.align 2, 0
_080A169C: .4byte 0x03000148
_080A16A0: .4byte EntityEF66_Update
_080A16A4: .4byte EntityEF66_Destroy
_080A16A8:
	adds r0, r4, #0
_080A16AA:
	pop {r4, r5}
	pop {r1}
	bx r1
