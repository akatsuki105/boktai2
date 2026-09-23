	push {r4, lr}
	ldr r0, _08049E1C @ =0x030000C8
	ldr r0, [r0]
	cmp r0, #0
	bne _08049E2A
	movs r1, #0xcc
	lsls r1, r1, #1
	movs r0, #3
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08049E28
	ldr r1, _08049E20 @ =EntityDFC6_Update
	ldr r2, _08049E24 @ =EntityDFC6_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl EntityDFC6_Init
	cmp r0, #0
	bge _08049E28
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08049E2A
	.align 2, 0
_08049E1C: .4byte 0x030000C8
_08049E20: .4byte EntityDFC6_Update
_08049E24: .4byte EntityDFC6_Destroy
_08049E28:
	adds r0, r4, #0
_08049E2A:
	pop {r4}
	pop {r1}
	bx r1
