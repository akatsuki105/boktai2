	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r4, r0, #0
	adds r6, r1, #0
	mov sb, r2
	mov sl, r3
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r0, [r0]
	movs r2, #0xd9
	lsls r2, r2, #2
	adds r1, r0, r2
	ldrh r1, [r1]
	ldr r5, _0808A648 @ =0x00000366
	adds r0, r0, r5
	ldrh r2, [r0]
	cmp r1, #0
	bne _0808A64C
	movs r1, #0
	movs r5, #0
	mov r8, r5
	b _0808A666
	.align 2, 0
_0808A648: .4byte 0x00000366
_0808A64C:
	subs r1, #1
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #4
	subs r0, r0, r1
	subs r1, r2, #1
	bl Div
	adds r1, r0, #1
	asrs r5, r1, #3
	lsls r0, r5, #3
	subs r0, r1, r0
	mov r8, r0
_0808A666:
	cmp r6, #0
	bne _0808A6B4
	movs r7, #0x43
	movs r0, #0x4b
	str r0, [sp]
	movs r6, #0x4c
	cmp r1, #0x27
	ble _0808A67C
	movs r4, #0xf8
	lsls r4, r4, #2
	b _0808A6A2
_0808A67C:
	cmp r1, #0x13
	ble _0808A688
	ldr r4, _0808A684 @ =0x0000029F
	b _0808A6A2
	.align 2, 0
_0808A684: .4byte 0x0000029F
_0808A688:
	movs r1, #0xa0
	lsls r1, r1, #4
	adds r3, r4, r1
	ldrh r2, [r3]
	lsrs r0, r2, #2
	movs r1, #1
	ands r0, r1
	movs r4, #0x12
	cmp r0, #0
	beq _0808A69E
	ldr r4, _0808A6B0 @ =0x0000109F
_0808A69E:
	adds r0, r2, #1
	strh r0, [r3]
_0808A6A2:
	movs r0, #0
	mov r1, sb
	mov r2, sl
	bl FUN_0808a420
	adds r3, r0, #0
	b _0808A6E2
	.align 2, 0
_0808A6B0: .4byte 0x0000109F
_0808A6B4:
	movs r7, #0x63
	movs r2, #0x6b
	str r2, [sp]
	ldr r6, _0808A750 @ =0x000004BD
	movs r4, #0xf8
	lsls r4, r4, #2
	cmp r1, #0x27
	bgt _0808A6CC
	ldr r4, _0808A754 @ =0x0000109F
	cmp r1, #0x13
	ble _0808A6CC
	ldr r4, _0808A758 @ =0x0000029F
_0808A6CC:
	mov r1, sb
	subs r1, #1
	movs r0, #0
	mov r2, sl
	bl FUN_0808a420
	adds r3, r0, #0
	ldr r2, _0808A75C @ =0x0000D0BD
	adds r1, r2, #0
	strh r1, [r3]
	adds r3, #2
_0808A6E2:
	ldr r2, _0808A760 @ =0x03004406
	ldrh r1, [r2]
	cmp r1, r4
	beq _0808A6EC
	strh r4, [r2]
_0808A6EC:
	movs r4, #0
	cmp r4, r5
	bge _0808A708
	ldr r2, _0808A764 @ =0xFFFFD000
	adds r1, r2, #0
	adds r2, r7, #0
	orrs r2, r1
	adds r4, r5, #0
_0808A6FC:
	strh r2, [r3]
	adds r3, #2
	subs r4, #1
	cmp r4, #0
	bne _0808A6FC
	adds r4, r5, #0
_0808A708:
	mov r5, r8
	cmp r5, #0
	beq _0808A720
	mov r1, r8
	subs r1, #8
	subs r1, r7, r1
	ldr r5, _0808A764 @ =0xFFFFD000
	adds r2, r5, #0
	orrs r1, r2
	strh r1, [r3]
	adds r3, #2
	adds r4, #1
_0808A720:
	cmp r4, #9
	bgt _0808A736
	ldr r2, _0808A764 @ =0xFFFFD000
	adds r1, r2, #0
	ldr r5, [sp]
	orrs r1, r5
_0808A72C:
	strh r1, [r3]
	adds r3, #2
	adds r4, #1
	cmp r4, #9
	ble _0808A72C
_0808A736:
	ldr r2, _0808A764 @ =0xFFFFD000
	adds r1, r2, #0
	orrs r6, r1
	strh r6, [r3]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0808A750: .4byte 0x000004BD
_0808A754: .4byte 0x0000109F
_0808A758: .4byte 0x0000029F
_0808A75C: .4byte 0x0000D0BD
_0808A760: .4byte 0x03004406
_0808A764: .4byte 0xFFFFD000
