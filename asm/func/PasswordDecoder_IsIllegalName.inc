	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r0
	movs r0, #0
	mov sb, r0
	mov r6, r8
	adds r6, #0x60
_0801124E:
	ldrh r0, [r6]
	cmp r0, #0
	beq _0801129A
	movs r7, #0
	movs r4, #0
	adds r5, r6, #0
_0801125A:
	mov r1, r8
	ldr r0, [r1, #0x78]
	bl VM_ParseStringRef
	adds r0, r0, r4
	bl Textbox_LookupString
	adds r1, r0, #0
	ldrb r0, [r1]
	adds r2, r4, #1
	b _08011274
_08011270:
	adds r1, #2
	ldrb r0, [r1]
_08011274:
	cmp r0, #0
	beq _08011282
	ldrb r0, [r1, #1]
	ldrh r3, [r5]
	cmp r0, r3
	bne _08011270
	movs r7, #1
_08011282:
	adds r4, r2, #0
	cmp r4, #1
	ble _0801125A
	cmp r7, #0
	bne _0801129A
	ldrh r0, [r6]
	cmp r0, #0xec
	beq _08011296
	movs r0, #1
	b _080112A8
_08011296:
	movs r0, #0xf0
	strh r0, [r6]
_0801129A:
	adds r6, #2
	movs r0, #1
	add sb, r0
	mov r1, sb
	cmp r1, #4
	ble _0801124E
	movs r0, #0
_080112A8:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
