	push {r4, lr}
	ldr r0, _081F53E0 @ =0x030001F8
	ldr r0, [r0]
	cmp r0, #0
	bne _081F53EE
	movs r1, #0xc4
	lsls r1, r1, #4
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081F53EC
	ldr r1, _081F53E4 @ =Entity081f53a8_Update
	ldr r2, _081F53E8 @ =Entity081f53a8_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity081f53a8_Init
	cmp r0, #0
	bge _081F53EC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081F53EE
	.align 2, 0
_081F53E0: .4byte 0x030001F8
_081F53E4: .4byte Entity081f53a8_Update
_081F53E8: .4byte Entity081f53a8_Destroy
_081F53EC:
	adds r0, r4, #0
_081F53EE:
	pop {r4}
	pop {r1}
	bx r1
