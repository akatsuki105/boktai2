	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08014718 @ =0x03000058
	ldr r0, [r0]
	cmp r0, #0
	bne _0801472A
	ldr r1, _0801471C @ =0x00000ABC
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08014728
	ldr r1, _08014720 @ =Entity080146e0_Update
	ldr r2, _08014724 @ =Entity080146e0_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl Entity080146e0_Init
	cmp r0, #0
	bge _08014728
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0801472A
	.align 2, 0
_08014718: .4byte 0x03000058
_0801471C: .4byte 0x00000ABC
_08014720: .4byte Entity080146e0_Update
_08014724: .4byte Entity080146e0_Destroy
_08014728:
	adds r0, r4, #0
_0801472A:
	pop {r4, r5}
	pop {r1}
	bx r1
