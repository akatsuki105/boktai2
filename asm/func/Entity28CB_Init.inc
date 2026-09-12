	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0
	adds r4, r1, #0
	movs r0, #0x4f
	bl VM_SeekToKeyword
	adds r1, r0, #0
	cmp r1, #0
	beq _0808A164
	bl Script_GetValue
	adds r1, r6, #0
	adds r1, #0x4c
	strh r0, [r1]
	adds r0, r1, #0
	b _0808A16A
_0808A164:
	adds r0, r6, #0
	adds r0, #0x4c
	strh r1, [r0]
_0808A16A:
	ldrh r1, [r0]
	cmp r1, #0
	beq _0808A18C
	adds r0, r6, #0
	adds r0, #0x18
	adds r1, r4, #0
	movs r2, #0xa
	bl FUN_080223f4
	movs r0, #0
	adds r1, r6, #0
	adds r1, #0x4e
	strh r0, [r1]
	str r0, [r6, #0x64]
	movs r0, #1
	mov sl, r0
	b _0808A1A2
_0808A18C:
	movs r0, #1
	adds r2, r6, #0
	adds r2, #0x4e
	strh r0, [r2]
	str r1, [r6, #0x64]
	movs r1, #0
	mov sl, r1
	movs r0, #0xe3
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0808A1A2:
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0808A1CC
	bl Script_GetValue
	adds r1, r6, #0
	adds r1, #0x6c
	strh r0, [r1]
	bl Script_GetValue
	adds r1, r6, #0
	adds r1, #0x6e
	strh r0, [r1]
	bl Script_GetValue
	adds r1, r6, #0
	adds r1, #0x70
	strh r0, [r1]
	b _0808A1E8
_0808A1CC:
	ldr r0, _0808A240 @ =0x030046A0
	ldr r1, [r0]
	ldrh r2, [r1, #0x30]
	adds r0, r6, #0
	adds r0, #0x6c
	strh r2, [r0]
	ldrh r0, [r1, #0x32]
	adds r2, r6, #0
	adds r2, #0x6e
	strh r0, [r2]
	ldrh r1, [r1, #0x34]
	adds r0, r6, #0
	adds r0, #0x70
	strh r1, [r0]
_0808A1E8:
	bl FUN_0808a11c
	adds r5, r6, #0
	adds r5, #0x50
	strh r0, [r5]
	movs r1, #0x80
	lsls r1, r1, #3
	movs r0, #0x68
	bl VM_GetKeywordValue
	adds r4, r6, #0
	adds r4, #0x58
	strh r0, [r4]
	adds r1, r6, #0
	adds r1, #0x5a
	strh r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #2
	movs r0, #0x6d
	bl VM_GetKeywordValue
	adds r1, r6, #0
	adds r1, #0x5c
	strh r0, [r1]
	adds r1, #2
	strh r0, [r1]
	subs r1, #0xc
	movs r0, #0xfe
	lsls r0, r0, #3
	strh r0, [r1]
	movs r0, #0x65
	bl VM_SeekToKeyword
	mov r8, r5
	mov sb, r4
	cmp r0, #0
	beq _0808A244
	bl Script_GetValue
	str r0, [r6, #0x68]
	bl Script_GetValue
	b _0808A246
	.align 2, 0
_0808A240: .4byte 0x030046A0
_0808A244:
	str r0, [r6, #0x68]
_0808A246:
	str r0, [r6, #0x54]
	movs r2, #0xa8
	lsls r2, r2, #1
	adds r0, r6, r2
	ldr r1, _0808A294 @ =0x00002499
	bl Video_GetActorSprite
	movs r5, #0
	movs r7, #1
_0808A258:
	movs r0, #0x2c
	muls r0, r5, r0
	adds r0, #0x74
	adds r4, r6, r0
	adds r0, r4, #0
	movs r2, #0xa8
	lsls r2, r2, #1
	adds r1, r6, r2
	movs r2, #2
	bl FUN_0822a470
	mov r0, r8
	ldrh r1, [r0]
	lsls r0, r1, #3
	subs r0, r0, r1
	strh r0, [r4, #0x10]
	ldr r0, [r6, #0x6c]
	ldr r1, [r6, #0x70]
	str r0, [r4, #0x1c]
	str r1, [r4, #0x20]
	cmp r5, #0
	bne _0808A298
	mov r1, sb
	ldrh r0, [r1]
	ldrh r2, [r4, #0x1e]
	adds r0, r0, r2
	strh r0, [r4, #0x1e]
	ldr r0, [r4]
	orrs r0, r7
	b _0808A2A4
	.align 2, 0
_0808A294: .4byte 0x00002499
_0808A298:
	ldr r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #2
	orrs r0, r1
	mov r1, sl
	orrs r0, r1
_0808A2A4:
	str r0, [r4]
	strb r7, [r4, #7]
	adds r5, #1
	cmp r5, #4
	ble _0808A258
	mov r2, r8
	ldrh r1, [r2]
	ldr r0, _0808A2EC @ =0x03003584
	ldr r2, _0808A2F0 @ =0x00000207
	adds r1, r1, r2
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	movs r1, #0xb8
	lsls r1, r1, #1
	adds r4, r6, r1
	ldr r2, _0808A2F4 @ =0x04000008
	adds r1, r4, #0
	bl CpuSet
	movs r2, #0xb6
	lsls r2, r2, #1
	adds r0, r6, r2
	str r4, [r0]
	movs r1, #0xae
	lsls r1, r1, #1
	adds r0, r6, r1
	str r4, [r0]
	movs r0, #0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0808A2EC: .4byte 0x03003584
_0808A2F0: .4byte 0x00000207
_0808A2F4: .4byte 0x04000008
