	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080B2824 @ =0x03002C58
	ldr r0, [r0]
	cmp r0, #0
	bne _080B2836
	ldr r1, _080B2828 @ =0x000017DC
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080B2834
	ldr r1, _080B282C @ =EntityCBB0_Update
	ldr r2, _080B2830 @ =EntityCBB0_Destroy
	bl SetEntityRoutine
	strh r5, [r4, #0x18]
	adds r0, r4, #0
	bl EntityCBB0_Init
	cmp r0, #0
	bge _080B2834
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080B2836
	.align 2, 0
_080B2824: .4byte 0x03002C58
_080B2828: .4byte 0x000017DC
_080B282C: .4byte EntityCBB0_Update
_080B2830: .4byte EntityCBB0_Destroy
_080B2834:
	adds r0, r4, #0
_080B2836:
	pop {r4, r5}
	pop {r1}
	bx r1
