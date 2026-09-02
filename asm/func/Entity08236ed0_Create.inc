	push {r4, r5, lr}
	ldr r5, _08236F00 @ =0x03000780
	ldr r0, [r5]
	cmp r0, #0
	bne _08236EF8
	movs r0, #0xb
	movs r1, #0xcc
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08236EF6
	ldr r1, _08236F04 @ =Entity08236ed0_Update
	ldr r2, _08236F08 @ =Entity08236ed0_Destroy
	bl SetEntityRoutine
	str r4, [r5]
	bl Entity08236ed0_Init
_08236EF6:
	adds r0, r4, #0
_08236EF8:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08236F00: .4byte 0x03000780
_08236F04: .4byte Entity08236ed0_Update
_08236F08: .4byte Entity08236ed0_Destroy
