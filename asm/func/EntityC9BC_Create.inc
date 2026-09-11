	push {r4, r5, lr}
	adds r5, r0, #0
	bl FUN_0800cb70
	adds r4, r0, #0
	cmp r4, #0
	bne _0800DB16
	movs r0, #9
	movs r1, #0x78
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0800DB14
	ldr r1, _0800DB0C @ =EntityC9BC_Update
	ldr r2, _0800DB10 @ =EntityC9BC_Destroy
	bl SetEntityRoutine
	movs r0, #0x6d
	movs r1, #4
	bl VM_GetKeywordValue
	str r0, [r4, #0x1c]
	adds r0, r4, #0
	adds r1, r5, #0
	bl EntityC9BC_Init
	cmp r0, #0
	bge _0800DB14
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0800DB16
	.align 2, 0
_0800DB0C: .4byte EntityC9BC_Update
_0800DB10: .4byte EntityC9BC_Destroy
_0800DB14:
	adds r0, r4, #0
_0800DB16:
	pop {r4, r5}
	pop {r1}
	bx r1
