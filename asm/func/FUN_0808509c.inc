	push {lr}
	mov ip, r0
	adds r0, #0xb0
	ldrb r0, [r0]
	cmp r0, #0
	bne _080850D0
	mov r1, ip
	adds r1, #0xb8
	ldrh r0, [r1]
	adds r3, r0, #0
	cmp r3, #0
	beq _080850B8
	subs r0, #1
	b _080850CE
_080850B8:
	mov r1, ip
	adds r1, #0xac
	mov r0, ip
	adds r0, #0xaf
	ldrb r2, [r0]
	ldrh r0, [r1]
	cmp r0, r2
	bhs _080850CC
	strh r3, [r1]
	b _080850D0
_080850CC:
	subs r0, r0, r2
_080850CE:
	strh r0, [r1]
_080850D0:
	mov r0, ip
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _08085138
	mov r1, ip
	adds r1, #0xb4
	ldrb r0, [r1]
	adds r0, #6
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bge _080850EE
	movs r0, #0x7f
	strb r0, [r1]
_080850EE:
	mov r1, ip
	adds r1, #0xb6
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r2, _08085118 @ =0x0000FFFF
	adds r1, r2, #0
	ands r0, r1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0808511C
	mov r2, ip
	adds r2, #0xc8
	ldr r0, [r2]
	ldr r1, [r2, #4]
	mov r3, ip
	str r0, [r3, #0x34]
	str r1, [r3, #0x38]
	adds r0, r2, #0
	b _0808512E
	.align 2, 0
_08085118: .4byte 0x0000FFFF
_0808511C:
	mov r0, ip
	adds r0, #0xc0
	ldr r1, [r0, #4]
	ldr r0, [r0]
	mov r2, ip
	str r0, [r2, #0x34]
	str r1, [r2, #0x38]
	mov r0, ip
	adds r0, #0xc8
_0808512E:
	mov r2, ip
	adds r2, #0x7c
	ldr r1, [r0, #4]
	ldr r0, [r0]
	b _08085162
_08085138:
	mov r1, ip
	adds r1, #0xb4
	ldrb r0, [r1]
	subs r0, #6
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x4f
	bhi _0808514E
	movs r0, #0x50
	strb r0, [r1]
_0808514E:
	mov r3, ip
	adds r3, #0xc0
	ldr r0, [r3]
	ldr r1, [r3, #4]
	mov r2, ip
	str r0, [r2, #0x34]
	str r1, [r2, #0x38]
	adds r2, #0x7c
	ldr r0, [r3]
	ldr r1, [r3, #4]
_08085162:
	str r0, [r2]
	str r1, [r2, #4]
	pop {r0}
	bx r0
	.align 2, 0
