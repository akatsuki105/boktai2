	push {r4, lr}
	ldr r0, _081F3358 @ =0x030001F0
	ldr r0, [r0]
	cmp r0, #0
	bne _081F336A
	ldr r1, _081F335C @ =0x00000BAC
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081F3368
	ldr r1, _081F3360 @ =Entity081f3324_Update
	ldr r2, _081F3364 @ =Entity081f3324_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity081f3324_Init
	cmp r0, #0
	bge _081F3368
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081F336A
	.align 2, 0
_081F3358: .4byte 0x030001F0
_081F335C: .4byte 0x00000BAC
_081F3360: .4byte Entity081f3324_Update
_081F3364: .4byte Entity081f3324_Destroy
_081F3368:
	adds r0, r4, #0
_081F336A:
	pop {r4}
	pop {r1}
	bx r1
