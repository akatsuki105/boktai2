	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r0
	movs r0, #0xac
	lsls r0, r0, #1
	bl sound_08240740
	ldr r0, _081D502C @ =0x00000261
	bl sound_08240740
	ldr r0, _081D5030 @ =0x00000289
	bl sound_08240740
	ldr r0, _081D5034 @ =0x0000028A
	bl sound_08240740
	movs r0, #0xa2
	lsls r0, r0, #2
	bl sound_08240740
	movs r7, #0
	movs r0, #1
	mov sb, r0
	mov r6, r8
	adds r6, #0xd0
	mov r5, r8
	adds r5, #0x1c
_081D5016:
	ldr r0, _081D5038 @ =0x000012AC
	add r0, r8
	mov r1, sb
	lsls r1, r7
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081D503C
	movs r0, #1
	b _081D503E
	.align 2, 0
_081D502C: .4byte 0x00000261
_081D5030: .4byte 0x00000289
_081D5034: .4byte 0x0000028A
_081D5038: .4byte 0x000012AC
_081D503C:
	movs r0, #0
_081D503E:
	cmp r0, #0
	beq _081D5076
	adds r4, r5, #0
	ldrh r0, [r6]
	mov r1, sb
	ands r0, r1
	cmp r0, #0
	beq _081D5052
	movs r0, #1
	b _081D5054
_081D5052:
	movs r0, #0
_081D5054:
	cmp r0, #0
	beq _081D5062
	movs r1, #0x9c
	lsls r1, r1, #1
	adds r0, r4, r1
	bl FUN_082342a8
_081D5062:
	adds r0, r4, #0
	bl Elevator_RemoveTileOverrides
	adds r0, r4, #0
	adds r0, #0xf4
	bl FUN_0823b284
	adds r0, r4, #0
	bl AuxSprite_Remove
_081D5076:
	movs r0, #0xc6
	lsls r0, r0, #1
	adds r6, r6, r0
	adds r5, r5, r0
	adds r7, #1
	cmp r7, #0xb
	ble _081D5016
	movs r1, #0
	ldr r0, _081D5098 @ =0x03000194
	str r1, [r0]
	movs r0, #0
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081D5098: .4byte 0x03000194
