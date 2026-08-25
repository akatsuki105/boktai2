	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080026E8 @ =gEntity4AE5
	ldr r0, [r0]
	cmp r0, #0
	bne _080026F6
	movs r1, #0xdf
	lsls r1, r1, #3
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080026F4
	ldr r1, _080026EC @ =Entity4AE5_Update
	ldr r2, _080026F0 @ =Entity4AE5_Destroy
	bl SetEntityRoutine
	lsls r1, r5, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl Entity4AE5_Init
	cmp r0, #0
	bge _080026F4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080026F6
	.align 2, 0
_080026E8: .4byte gEntity4AE5
_080026EC: .4byte Entity4AE5_Update
_080026F0: .4byte Entity4AE5_Destroy
_080026F4:
	adds r0, r4, #0
_080026F6:
	pop {r4, r5}
	pop {r1}
	bx r1
