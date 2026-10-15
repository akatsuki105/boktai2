	push {r4, lr}
	movs r0, #0xb
	movs r1, #0x2c
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08019AE0
	ldr r1, _08019AD8 @ =Entity82B7_Update
	ldr r2, _08019ADC @ =Entity82B7_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity82B7_Init
	cmp r0, #0
	bge _08019AE0
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08019AE2
	.align 2, 0
_08019AD8: .4byte Entity82B7_Update
_08019ADC: .4byte Entity82B7_Destroy
_08019AE0:
	adds r0, r4, #0
_08019AE2:
	pop {r4}
	pop {r1}
	bx r1
