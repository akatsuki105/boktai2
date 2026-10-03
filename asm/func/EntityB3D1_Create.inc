	push {r4, lr}
	ldr r0, _080C0ACC @ =0x03000158
	ldr r0, [r0]
	cmp r0, #0
	bne _080C0ADE
	ldr r1, _080C0AD0 @ =0x000005BC
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080C0ADC
	ldr r1, _080C0AD4 @ =EntityB3D1_Update
	ldr r2, _080C0AD8 @ =EntityB3D1_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl EntityB3D1_Init
	cmp r0, #0
	bge _080C0ADC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080C0ADE
	.align 2, 0
_080C0ACC: .4byte 0x03000158
_080C0AD0: .4byte 0x000005BC
_080C0AD4: .4byte EntityB3D1_Update
_080C0AD8: .4byte EntityB3D1_Destroy
_080C0ADC:
	adds r0, r4, #0
_080C0ADE:
	pop {r4}
	pop {r1}
	bx r1
