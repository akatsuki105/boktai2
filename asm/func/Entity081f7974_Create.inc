	push {r4, lr}
	ldr r0, _081F79A8 @ =0x03000200
	ldr r0, [r0]
	cmp r0, #0
	bne _081F79BA
	ldr r1, _081F79AC @ =0x000004BC
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081F79B8
	ldr r1, _081F79B0 @ =Entity081f7974_Update
	ldr r2, _081F79B4 @ =Entity081f7974_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity081f7974_Init
	cmp r0, #0
	bge _081F79B8
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081F79BA
	.align 2, 0
_081F79A8: .4byte 0x03000200
_081F79AC: .4byte 0x000004BC
_081F79B0: .4byte Entity081f7974_Update
_081F79B4: .4byte Entity081f7974_Destroy
_081F79B8:
	adds r0, r4, #0
_081F79BA:
	pop {r4}
	pop {r1}
	bx r1
