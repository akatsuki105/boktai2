	push {r4, lr}
	bl GetEntity723E
	adds r4, r0, #0
	cmp r4, #0
	bne _08052B36
	ldr r1, _08052B28 @ =0x000008E8
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08052B34
	ldr r1, _08052B2C @ =Entity723E_Update
	ldr r2, _08052B30 @ =Entity723E_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity723E_Init
	cmp r0, #0
	bge _08052B34
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08052B36
	.align 2, 0
_08052B28: .4byte 0x000008E8
_08052B2C: .4byte Entity723E_Update
_08052B30: .4byte Entity723E_Destroy
_08052B34:
	adds r0, r4, #0
_08052B36:
	pop {r4}
	pop {r1}
	bx r1
