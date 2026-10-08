	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	adds r7, r2, #0
	ldr r0, _080A0F98 @ =0x03002C3C
	ldr r4, [r0]
	cmp r4, #0
	bne _080A0FA4
	movs r0, #9
	movs r1, #0x38
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A0FA4
	ldr r1, _080A0F9C @ =EntityA628_Update
	ldr r2, _080A0FA0 @ =EntityA628_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	adds r3, r7, #0
	bl EntityA628_Init
	cmp r0, #0
	bge _080A0FA4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A0FA6
	.align 2, 0
_080A0F98: .4byte 0x03002C3C
_080A0F9C: .4byte EntityA628_Update
_080A0FA0: .4byte EntityA628_Destroy
_080A0FA4:
	adds r0, r4, #0
_080A0FA6:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
