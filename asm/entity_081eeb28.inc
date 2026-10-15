	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_081ee800
FUN_081ee800: @ 0x081EE800
	bx lr
	.align 2, 0

	thumb_func_start FUN_081ee804
FUN_081ee804: @ 0x081EE804
	push {r4, r5, lr}
	movs r2, #0
	movs r1, #0x97
	lsls r1, r1, #2
	adds r3, r0, r1
	movs r5, #1
	movs r1, #0x47
	adds r1, r1, r0
	mov ip, r1
	adds r4, r0, #0
	adds r4, #0x1c
_081EE81A:
	adds r1, r5, #0
	lsls r1, r2
	ldr r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _081EE82A
	movs r0, #1
	b _081EE82C
_081EE82A:
	movs r0, #0
_081EE82C:
	cmp r0, #0
	bne _081EE842
	adds r1, r5, #0
	lsls r1, r2
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	mov r0, ip
	strb r2, [r0]
	adds r0, r4, #0
	b _081EE850
_081EE842:
	movs r1, #0x30
	add ip, r1
	adds r4, #0x30
	adds r2, #1
	cmp r2, #0xb
	ble _081EE81A
	movs r0, #0
_081EE850:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081ee858
FUN_081ee858: @ 0x081EE858
	push {r4, r5, r6, lr}
	adds r2, r1, #0
	adds r4, r2, #0
	movs r5, #0
	ldrh r0, [r2, #0x2c]
	cmp r0, #0
	beq _081EE868
	strh r5, [r2, #0x2c]
_081EE868:
	ldr r0, _081EE8B0 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _081EE8CC
	ldr r0, _081EE8B4 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081EE900
	movs r1, #0x18
	ldrsh r0, [r0, r1]
	cmp r0, #0
	blt _081EE900
	ldr r1, _081EE8B8 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _081EE8C4
	ldr r3, _081EE8BC @ =0x00000446
	adds r0, r1, r3
	ldrh r0, [r0]
	movs r3, #0
	cmp r0, #0
	beq _081EE8AA
	ldr r6, _081EE8C0 @ =0x00000442
	adds r0, r1, r6
	ldrh r0, [r0]
	cmp r0, #4
	bne _081EE8AA
	movs r3, #1
_081EE8AA:
	adds r0, r3, #0
	b _081EE8C6
	.align 2, 0
_081EE8B0: .4byte 0x030047A4
_081EE8B4: .4byte 0x03002C68
_081EE8B8: .4byte 0x03002BE0
_081EE8BC: .4byte 0x00000446
_081EE8C0: .4byte 0x00000442
_081EE8C4:
	movs r0, #0
_081EE8C6:
	cmp r0, #0
	beq _081EE900
	b _081EE904
_081EE8CC:
	ldr r0, _081EE92C @ =0x03002B48
	ldr r0, [r0]
	cmp r0, #0
	bgt _081EE8FE
	ldr r0, _081EE930 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x94
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #2
	beq _081EE8FE
	ldr r0, _081EE934 @ =0x03002B8C
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _081EE8FA
	ldr r0, _081EE938 @ =0x03002B60
	ldrh r0, [r0]
	cmp r0, #4
	bne _081EE8FA
	movs r1, #1
_081EE8FA:
	cmp r1, #0
	beq _081EE900
_081EE8FE:
	movs r5, #1
_081EE900:
	cmp r5, #0
	beq _081EE954
_081EE904:
	ldrh r1, [r2, #0x28]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	bne _081EE922
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	ldrh r1, [r2, #0x28]
	movs r0, #1
	orrs r0, r1
	strh r0, [r2, #0x28]
_081EE922:
	ldrh r0, [r2, #0x2e]
	cmp r0, #0
	beq _081EE93C
	subs r0, #1
	b _081EE966
	.align 2, 0
_081EE92C: .4byte 0x03002B48
_081EE930: .4byte 0x030046A0
_081EE934: .4byte 0x03002B8C
_081EE938: .4byte 0x03002B60
_081EE93C:
	ldr r1, [r2]
	adds r0, r1, #0
	ands r0, r3
	cmp r0, #0
	beq _081EE94E
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	b _081EE950
_081EE94E:
	orrs r1, r3
_081EE950:
	str r1, [r2]
	b _081EE964
_081EE954:
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	ldrh r1, [r2, #0x28]
	ldr r0, _081EE970 @ =0x0000FFFE
	ands r0, r1
	strh r0, [r2, #0x28]
_081EE964:
	movs r0, #0x26
_081EE966:
	strh r0, [r2, #0x2e]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081EE970: .4byte 0x0000FFFE

	thumb_func_start FUN_081ee974
FUN_081ee974: @ 0x081EE974
	push {r4, r5, r6, lr}
	adds r5, r1, #0
	ldrh r0, [r5, #0x2c]
	cmp r0, #0
	beq _081EE982
	movs r0, #0
	strh r0, [r5, #0x2c]
_081EE982:
	ldr r0, _081EE9B8 @ =0x030001D4
	ldr r2, [r0]
	adds r6, r5, #0
	adds r6, #0x2b
	movs r0, #0
	ldrsb r0, [r6, r0]
	movs r1, #0x97
	lsls r1, r1, #2
	adds r2, r2, r1
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
	adds r0, r5, #0
	adds r0, #0x2a
	movs r4, #0
	strb r4, [r0]
	adds r0, r5, #0
	bl Particle_Remove
	movs r0, #0xff
	strb r0, [r6]
	strh r4, [r5, #0x28]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081EE9B8: .4byte 0x030001D4

	thumb_func_start FUN_081ee9bc
FUN_081ee9bc: @ 0x081EE9BC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	ldr r0, _081EEA34 @ =0x030001D4
	ldr r7, [r0]
	cmp r7, #0
	bne _081EE9D6
	bl Entity081eeb28_Create
	adds r7, r0, #0
	cmp r7, #0
	beq _081EEA38
_081EE9D6:
	adds r0, r7, #0
	bl FUN_081ee804
	adds r6, r0, #0
	cmp r6, #0
	beq _081EEA38
	adds r1, r6, #0
	adds r1, #0x2a
	movs r0, #0
	movs r4, #1
	strb r4, [r1]
	strh r0, [r6, #0x28]
	strh r0, [r6, #0x2e]
	movs r0, #1
	mov r8, r0
	strh r4, [r6, #0x2c]
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r6, #0x18]
	str r1, [r6, #0x1c]
	ldrh r0, [r6, #0x1a]
	adds r0, #0x1e
	strh r0, [r6, #0x1a]
	ldr r1, [r7, #0x18]
	adds r0, r6, #0
	movs r2, #0
	bl Particle_Add
	movs r2, #8
	rsbs r2, r2, #0
	adds r0, r6, #0
	adds r1, r2, #0
	bl Particle_SetOffset
	ldr r1, [r7, #0x18]
	adds r0, r6, #0
	movs r2, #0x34
	bl Particle_SetFrame
	ldr r0, [r6]
	orrs r0, r4
	str r0, [r6]
	mov r0, r8
	strb r0, [r6, #0xf]
	adds r0, r6, #0
	b _081EEA3A
	.align 2, 0
_081EEA34: .4byte 0x030001D4
_081EEA38:
	movs r0, #0
_081EEA3A:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start Entity081eeb28_Update
Entity081eeb28_Update: @ 0x081EEA44
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	adds r1, r7, #0
	adds r1, #0x1c
	movs r2, #0x97
	lsls r2, r2, #2
	adds r0, r7, r2
	ldr r0, [r0]
	cmp r0, #0
	beq _081EEAA8
	movs r6, #0
	movs r0, #0x97
	lsls r0, r0, #2
	adds r0, r0, r7
	mov r8, r0
	ldr r2, _081EEA84 @ =0x085AE4E0
	mov sb, r2
	adds r5, r7, #0
	adds r5, #0x46
	adds r4, r1, #0
_081EEA72:
	movs r1, #1
	lsls r1, r6
	mov r2, r8
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081EEA88
	movs r0, #1
	b _081EEA8A
	.align 2, 0
_081EEA84: .4byte 0x085AE4E0
_081EEA88:
	movs r0, #0
_081EEA8A:
	cmp r0, #0
	beq _081EEA9E
	ldrb r0, [r5]
	lsls r0, r0, #2
	add r0, sb
	ldr r2, [r0]
	adds r0, r7, #0
	adds r1, r4, #0
	bl _call_via_r2
_081EEA9E:
	adds r5, #0x30
	adds r4, #0x30
	adds r6, #1
	cmp r6, #0xb
	ble _081EEA72
_081EEAA8:
	movs r0, #0
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity081eeb28_Destroy
Entity081eeb28_Destroy: @ 0x081EEAB8
	push {r4, r5, r6, lr}
	movs r5, #0
	movs r1, #0x97
	lsls r1, r1, #2
	adds r6, r0, r1
	adds r4, r0, #0
	adds r4, #0x1c
_081EEAC6:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081EEAD6
	movs r0, #1
	b _081EEAD8
_081EEAD6:
	movs r0, #0
_081EEAD8:
	cmp r0, #0
	beq _081EEAE2
	adds r0, r4, #0
	bl Particle_Remove
_081EEAE2:
	adds r4, #0x30
	adds r5, #1
	cmp r5, #0xb
	ble _081EEAC6
	movs r1, #0
	ldr r0, _081EEAF8 @ =0x030001D4
	str r1, [r0]
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_081EEAF8: .4byte 0x030001D4

	thumb_func_start Entity081eeb28_Init
Entity081eeb28_Init: @ 0x081EEAFC
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _081EEB20 @ =0x00001C1A
	bl GetParticleGroup
	str r0, [r4, #0x18]
	movs r0, #0x97
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #0
	str r0, [r1]
	ldr r0, _081EEB24 @ =0x030001D4
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081EEB20: .4byte 0x00001C1A
_081EEB24: .4byte 0x030001D4

	thumb_func_start Entity081eeb28_Create
Entity081eeb28_Create: @ 0x081EEB28
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

	thumb_func_start FUN_081eeb74
FUN_081eeb74: @ 0x081EEB74
	ldr r1, _081EEB7C @ =0x030001D4
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081EEB7C: .4byte 0x030001D4
