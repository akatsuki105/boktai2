	push {r4, lr}
	ldr r0, _081EEB60 @ =0x030001D4
	ldr r0, [r0]
	cmp r0, #0
	bne _081EEB6E
	movs r1, #0x98
	lsls r1, r1, #2
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081EEB6C
	ldr r1, _081EEB64 @ =Entity081eeb28_Update
	ldr r2, _081EEB68 @ =Entity081eeb28_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity081eeb28_Init
	cmp r0, #0
	bge _081EEB6C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081EEB6E
	.align 2, 0
_081EEB60: .4byte 0x030001D4
_081EEB64: .4byte Entity081eeb28_Update
_081EEB68: .4byte Entity081eeb28_Destroy
_081EEB6C:
	adds r0, r4, #0
_081EEB6E:
	pop {r4}
	pop {r1}
	bx r1
