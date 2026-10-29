	push {r4, r5, lr}
	ldr r5, _08149F68 @ =0x00000694
	adds r0, r5, #0
	bl Malloc
	adds r4, r0, #0
	cmp r4, #0
	beq _08149F60
	adds r1, r5, #0
	bl ClearMemory
	adds r0, r4, #0
	bl EnemyMimic_Init
	cmp r0, #0
	bge _08149F60
	adds r0, r4, #0
	bl EnemyMimic_Destroy
	adds r0, r4, #0
	bl Free
_08149F60:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08149F68: .4byte 0x00000694
