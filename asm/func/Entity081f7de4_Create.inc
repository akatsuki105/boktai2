	push {r4, lr}
	ldr r0, _081F7E1C @ =0x03000204
	ldr r0, [r0]
	cmp r0, #0
	bne _081F7E2A
	movs r1, #0xba
	lsls r1, r1, #1
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081F7E28
	ldr r1, _081F7E20 @ =Entity081f7de4_Update
	ldr r2, _081F7E24 @ =Entity081f7de4_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity081f7de4_Init
	cmp r0, #0
	bge _081F7E28
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081F7E2A
	.align 2, 0
_081F7E1C: .4byte 0x03000204
_081F7E20: .4byte Entity081f7de4_Update
_081F7E24: .4byte Entity081f7de4_Destroy
_081F7E28:
	adds r0, r4, #0
_081F7E2A:
	pop {r4}
	pop {r1}
	bx r1
