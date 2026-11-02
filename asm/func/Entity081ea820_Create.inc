	push {r4, lr}
	ldr r0, _081EA858 @ =0x030001BC
	ldr r0, [r0]
	cmp r0, #0
	bne _081EA866
	movs r1, #0xdb
	lsls r1, r1, #3
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081EA864
	ldr r1, _081EA85C @ =Entity081ea820_Update
	ldr r2, _081EA860 @ =Entity081ea820_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity081ea820_Init
	cmp r0, #0
	bge _081EA864
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081EA866
	.align 2, 0
_081EA858: .4byte 0x030001BC
_081EA85C: .4byte Entity081ea820_Update
_081EA860: .4byte Entity081ea820_Destroy
_081EA864:
	adds r0, r4, #0
_081EA866:
	pop {r4}
	pop {r1}
	bx r1
