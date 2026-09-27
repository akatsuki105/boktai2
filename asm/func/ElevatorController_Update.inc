	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r0
	mov r3, r8
	adds r3, #0x1c
	ldr r0, _081D4EF0 @ =0x000012AC
	add r0, r8
	ldr r0, [r0]
	cmp r0, #0
	bne _081D4EAA
	b _081D4FC6
_081D4EAA:
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r0, _081D4EF4 @ =0x030047A4
	ldr r1, _081D4EF8 @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	bne _081D4ECA
	movs r1, #4
	ldr r0, _081D4EFC @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081D4F0C
_081D4ECA:
	movs r0, #0xac
	lsls r0, r0, #1
	bl sound_08240740
	ldr r0, _081D4F00 @ =0x00000261
	bl sound_08240740
	ldr r0, _081D4F04 @ =0x00000289
	bl sound_08240740
	ldr r0, _081D4F08 @ =0x0000028A
	bl sound_08240740
	movs r0, #0xa2
	lsls r0, r0, #2
	bl sound_08240740
	b _081D4FC6
	.align 2, 0
_081D4EF0: .4byte 0x000012AC
_081D4EF4: .4byte 0x030047A4
_081D4EF8: .4byte 0x030047A0
_081D4EFC: .4byte 0x03002BC0
_081D4F00: .4byte 0x00000261
_081D4F04: .4byte 0x00000289
_081D4F08: .4byte 0x0000028A
_081D4F0C:
	ldr r0, _081D4F40 @ =0x030044BC
	ldr r0, [r0]
	movs r1, #8
	ands r0, r1
	cmp r0, #0
	bne _081D4FC6
	movs r0, #0
	mov sb, r0
	mov r6, r8
	adds r6, #0x38
	mov r7, r8
	adds r7, #0xce
	mov r5, r8
	adds r5, #0xf4
	adds r4, r3, #0
_081D4F2A:
	ldr r0, _081D4F44 @ =0x000012AC
	add r0, r8
	movs r1, #1
	mov r2, sb
	lsls r1, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081D4F48
	movs r0, #1
	b _081D4F4A
	.align 2, 0
_081D4F40: .4byte 0x030044BC
_081D4F44: .4byte 0x000012AC
_081D4F48:
	movs r0, #0
_081D4F4A:
	cmp r0, #0
	beq _081D4FAA
	movs r1, #0
	ldrsh r0, [r7, r1]
	cmp r0, #6
	beq _081D4FAA
	ldr r1, [r5]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _081D4FD4 @ =0x085AE0E8
	movs r2, #0
	ldrsh r0, [r7, r2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, [r5, #4]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, [r5, #8]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl Elevator_UpdateTileOverrides
	adds r0, r4, #0
	bl FUN_081d4540
	adds r0, r4, #0
	bl FUN_081d276c
	ldr r0, [r5, #0x24]
	ldr r1, [r5, #0x28]
	str r0, [r6]
	str r1, [r6, #4]
	ldr r1, _081D4FD8 @ =0xFFFFFF00
	adds r0, r1, #0
	ldrh r2, [r6]
	adds r0, r0, r2
	strh r0, [r6]
	adds r0, r4, #0
	bl Elevator_UpdateShake
_081D4FAA:
	movs r0, #0xc6
	lsls r0, r0, #1
	adds r6, r6, r0
	adds r7, r7, r0
	adds r5, r5, r0
	adds r4, r4, r0
	movs r1, #1
	add sb, r1
	mov r2, sb
	cmp r2, #0xb
	ble _081D4F2A
	mov r0, r8
	bl FUN_081d2a64
_081D4FC6:
	movs r0, #0
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081D4FD4: .4byte 0x085AE0E8
_081D4FD8: .4byte 0xFFFFFF00
