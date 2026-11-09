	push {r4, lr}
	ldr r0, _08204CF0 @ =0x03000220
	ldr r0, [r0]
	cmp r0, #0
	bne _08204CFE
	movs r1, #0x90
	lsls r1, r1, #3
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08204CFC
	ldr r1, _08204CF4 @ =Entity08204cb8_Update
	ldr r2, _08204CF8 @ =Entity08204cb8_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity08204cb8_Init
	cmp r0, #0
	bge _08204CFC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08204CFE
	.align 2, 0
_08204CF0: .4byte 0x03000220
_08204CF4: .4byte Entity08204cb8_Update
_08204CF8: .4byte Entity08204cb8_Destroy
_08204CFC:
	adds r0, r4, #0
_08204CFE:
	pop {r4}
	pop {r1}
	bx r1
