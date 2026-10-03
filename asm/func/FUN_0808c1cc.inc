	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	mov sl, r0
	ldr r0, _0808C1E8 @ =0x000009DE
	add r0, sl
	ldrb r0, [r0]
	cmp r0, #0
	bne _0808C1EC
	movs r0, #1
	b _0808C316
	.align 2, 0
_0808C1E8: .4byte 0x000009DE
_0808C1EC:
	ldr r1, _0808C244 @ =0x03003584
	ldr r0, _0808C248 @ =0x000009D8
	add r0, sl
	ldrh r0, [r0]
	lsls r0, r0, #5
	ldr r1, [r1]
	adds r0, r1, r0
	str r0, [sp]
	ldr r0, _0808C24C @ =0x000009DA
	add r0, sl
	ldrh r0, [r0]
	lsls r0, r0, #5
	adds r1, r1, r0
	mov sb, r1
	ldr r2, _0808C250 @ =0x000009DC
	add r2, sl
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	ldr r1, _0808C254 @ =0x000009DD
	add r1, sl
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r3, [r1]
	cmp r0, r3
	blo _0808C260
	ldr r1, _0808C258 @ =0x000009B8
	add r1, sl
	movs r7, #0xf
_0808C226:
	mov r2, sb
	ldrh r0, [r2]
	strh r0, [r1]
	movs r3, #2
	add sb, r3
	adds r1, #2
	subs r7, #1
	cmp r7, #0
	bge _0808C226
	ldr r1, _0808C25C @ =0x000009DE
	add r1, sl
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0808C316
	.align 2, 0
_0808C244: .4byte 0x03003584
_0808C248: .4byte 0x000009D8
_0808C24C: .4byte 0x000009DA
_0808C250: .4byte 0x000009DC
_0808C254: .4byte 0x000009DD
_0808C258: .4byte 0x000009B8
_0808C25C: .4byte 0x000009DE
_0808C260:
	ldrb r1, [r1]
	ldrb r0, [r2]
	subs r1, r1, r0
	str r1, [sp, #4]
	movs r7, #0
	ldr r0, _0808C328 @ =0x000009DC
	add r0, sl
	str r0, [sp, #8]
	ldr r1, _0808C32C @ =0x000009DD
	add r1, sl
	str r1, [sp, #0xc]
_0808C276:
	cmp r7, #5
	beq _0808C304
	cmp r7, #0xd
	beq _0808C304
	ldr r2, [sp]
	ldrh r5, [r2]
	movs r0, #0x1f
	ands r0, r5
	lsls r5, r5, #0x10
	lsrs r3, r5, #0x15
	movs r1, #0x1f
	ands r3, r1
	lsrs r5, r5, #0x1a
	ands r5, r1
	mov r2, sb
	ldrh r4, [r2]
	movs r2, #0x1f
	ands r2, r4
	lsls r4, r4, #0x10
	lsrs r6, r4, #0x15
	ands r6, r1
	lsrs r4, r4, #0x1a
	ands r4, r1
	ldr r1, [sp, #4]
	muls r0, r1, r0
	ldr r1, [sp, #8]
	ldrb r1, [r1]
	mov r8, r1
	mov r1, r8
	muls r1, r2, r1
	adds r0, r0, r1
	ldr r2, [sp, #0xc]
	ldrb r1, [r2]
	str r3, [sp, #0x10]
	bl Div
	mov r8, r0
	ldr r3, [sp, #0x10]
	ldr r1, [sp, #4]
	adds r0, r3, #0
	muls r0, r1, r0
	ldr r2, [sp, #8]
	ldrb r1, [r2]
	muls r1, r6, r1
	adds r0, r0, r1
	ldr r3, [sp, #0xc]
	ldrb r1, [r3]
	bl Div
	adds r6, r0, #0
	ldr r1, [sp, #4]
	adds r0, r5, #0
	muls r0, r1, r0
	ldr r2, [sp, #8]
	ldrb r1, [r2]
	muls r1, r4, r1
	adds r0, r0, r1
	ldr r3, [sp, #0xc]
	ldrb r1, [r3]
	bl Div
	lsls r1, r7, #1
	ldr r2, _0808C330 @ =0x000009B8
	add r2, sl
	adds r2, r2, r1
	lsls r0, r0, #0xa
	lsls r6, r6, #5
	orrs r0, r6
	mov r1, r8
	orrs r0, r1
	strh r0, [r2]
_0808C304:
	ldr r2, [sp]
	adds r2, #2
	str r2, [sp]
	movs r3, #2
	add sb, r3
	adds r7, #1
	cmp r7, #0xf
	ble _0808C276
	movs r0, #0
_0808C316:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0808C328: .4byte 0x000009DC
_0808C32C: .4byte 0x000009DD
_0808C330: .4byte 0x000009B8
