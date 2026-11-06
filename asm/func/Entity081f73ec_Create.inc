	push {r4, lr}
	ldr r0, _081F7424 @ =0x030001FC
	ldr r0, [r0]
	cmp r0, #0
	bne _081F7432
	movs r1, #0xe5
	lsls r1, r1, #3
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081F7430
	ldr r1, _081F7428 @ =Entity081f73ec_Update
	ldr r2, _081F742C @ =Entity081f73ec_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity081f73ec_Init
	cmp r0, #0
	bge _081F7430
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081F7432
	.align 2, 0
_081F7424: .4byte 0x030001FC
_081F7428: .4byte Entity081f73ec_Update
_081F742C: .4byte Entity081f73ec_Destroy
_081F7430:
	adds r0, r4, #0
_081F7432:
	pop {r4}
	pop {r1}
	bx r1
