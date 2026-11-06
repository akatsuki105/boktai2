	push {r4, lr}
	ldr r0, _081F458C @ =0x030001F4
	ldr r0, [r0]
	cmp r0, #0
	bne _081F459A
	movs r1, #0xbe
	lsls r1, r1, #3
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081F4598
	ldr r1, _081F4590 @ =Entity081f4554_Update
	ldr r2, _081F4594 @ =Entity081f4554_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity081f4554_Init
	cmp r0, #0
	bge _081F4598
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081F459A
	.align 2, 0
_081F458C: .4byte 0x030001F4
_081F4590: .4byte Entity081f4554_Update
_081F4594: .4byte Entity081f4554_Destroy
_081F4598:
	adds r0, r4, #0
_081F459A:
	pop {r4}
	pop {r1}
	bx r1
