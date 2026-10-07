	push {r4, r5, r6, r7, lr}
	sub sp, #4
	ldr r0, _081D8B34 @ =0x030001A4
	ldr r6, [r0]
	cmp r6, #0
	bne _081D8AB0
	bl Entity8CC7_Create
	adds r6, r0, #0
	cmp r6, #0
	bne _081D8AB0
	b _081D8C78
_081D8AB0:
	adds r0, r6, #0
	bl Entity8CC7_AllocElem
	adds r5, r0, #0
	cmp r5, #0
	bne _081D8ABE
	b _081D8C78
_081D8ABE:
	adds r7, r5, #0
	adds r4, r5, #0
	adds r4, #0x3c
	ldr r1, _081D8B38 @ =0x00005A6E
	adds r0, r4, #0
	bl Video_GetAuxSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	ldr r0, [r5, #0xc]
	ldr r1, _081D8B3C @ =0x0000014F
	bl Video_SetAuxSpritePltt
	adds r1, r5, #0
	adds r1, #0x68
	movs r2, #1
	movs r0, #1
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0x74
	strb r2, [r0]
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081D8B0A
	bl VM_GetValue
	strh r0, [r5, #0x1c]
	bl VM_GetValue
	strh r0, [r5, #0x1e]
	bl VM_GetValue
	strh r0, [r5, #0x20]
_081D8B0A:
	movs r0, #0x72
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081D8B40
	bl VM_GetValue
	adds r1, r5, #0
	adds r1, #0x60
	strh r0, [r1]
	bl VM_GetValue
	adds r1, r5, #0
	adds r1, #0x62
	strh r0, [r1]
	bl VM_GetValue
	adds r1, r5, #0
	adds r1, #0x64
	strh r0, [r1]
	b _081D8B52
	.align 2, 0
_081D8B34: .4byte 0x030001A4
_081D8B38: .4byte 0x00005A6E
_081D8B3C: .4byte 0x0000014F
_081D8B40:
	adds r0, r5, #0
	adds r0, #0x60
	movs r1, #0x80
	lsls r1, r1, #1
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
_081D8B52:
	movs r1, #0
	movs r0, #2
	strb r0, [r7, #7]
	adds r0, r5, #0
	adds r0, #0x6e
	strh r1, [r0]
	ldr r2, _081D8BB4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081D8BB8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081D8BBC @ =0x0203B400
	adds r0, r0, r1
	ldrh r2, [r0]
	movs r0, #1
	ands r2, r0
	adds r4, r5, #0
	adds r4, #0x2c
	ldr r1, [r6, #0x18]
	str r2, [sp]
	adds r0, r4, #0
	movs r2, #4
	movs r3, #0
	bl AuxAnim_SetAnim
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x2c]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D8BC0
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _081D8BC8
	.align 2, 0
_081D8BB4: .4byte 0x030046B8
_081D8BB8: .4byte 0x000003FF
_081D8BBC: .4byte 0x0203B400
_081D8BC0:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D8BC8:
	str r0, [r7]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D8BEC
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _081D8BF4
_081D8BEC:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D8BF4:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D8C2C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D8C64
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D8C30
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D8C24
	ldrb r0, [r4, #5]
_081D8C24:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D8C40
	.align 2, 0
_081D8C2C: .4byte 0x0000FFFF
_081D8C30:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D8C40
	strh r1, [r4, #8]
_081D8C40:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D8C64
	movs r0, #1
	strb r0, [r4, #7]
_081D8C64:
	adds r0, r5, #0
	adds r0, #0x7c
	adds r1, r5, #0
	adds r1, #0x1c
	movs r2, #0
	bl ParticleShadow_Init
	adds r1, r5, #0
	adds r1, #0x79
	strb r0, [r1]
_081D8C78:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
