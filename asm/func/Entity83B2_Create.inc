	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _0800983C @ =0x0300003C
	ldr r0, [r0]
	cmp r0, #0
	bne _0800984A
	movs r0, #8
	movs r1, #0x30
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08009848
	ldr r1, _08009840 @ =Entity83B2_Update
	ldr r2, _08009844 @ =Entity83B2_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl Entity83B2_Init
	cmp r0, #0
	bge _08009848
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0800984A
	.align 2, 0
_0800983C: .4byte 0x0300003C
_08009840: .4byte Entity83B2_Update
_08009844: .4byte Entity83B2_Destroy
_08009848:
	adds r0, r4, #0
_0800984A:
	pop {r4, r5}
	pop {r1}
	bx r1
