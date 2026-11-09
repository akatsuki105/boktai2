	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, _0805F30C @ =0x00000744
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0805F318
	ldr r1, _0805F310 @ =Entity0805f2dc_Update
	ldr r2, _0805F314 @ =Entity0805f2dc_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl Entity0805f2dc_Init
	cmp r0, #0
	bge _0805F318
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0805F31A
	.align 2, 0
_0805F30C: .4byte 0x00000744
_0805F310: .4byte Entity0805f2dc_Update
_0805F314: .4byte Entity0805f2dc_Destroy
_0805F318:
	adds r0, r4, #0
_0805F31A:
	pop {r4, r5}
	pop {r1}
	bx r1
