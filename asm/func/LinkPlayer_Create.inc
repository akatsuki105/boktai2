	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r0, _080846B0 @ =0x03002BE0
	ldr r0, [r0, #4]
	cmp r0, #0
	bne _080846C2
	ldr r1, _080846B4 @ =0x00000AC4
	movs r0, #6
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080846C0
	ldr r1, _080846B8 @ =LinkPlayer_Update
	ldr r2, _080846BC @ =LinkPlayer_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl LinkPlayer_Init
	cmp r0, #0
	bge _080846C0
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080846C2
	.align 2, 0
_080846B0: .4byte 0x03002BE0
_080846B4: .4byte 0x00000AC4
_080846B8: .4byte LinkPlayer_Update
_080846BC: .4byte LinkPlayer_Destroy
_080846C0:
	adds r0, r4, #0
_080846C2:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
