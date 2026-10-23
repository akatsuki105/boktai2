	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #1
	ldr r2, _081E2F00 @ =0x00001610
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081E2F04
	movs r0, #1
	b _081E2F06
	.align 2, 0
_081E2F00: .4byte 0x00001610
_081E2F04:
	movs r0, #0
_081E2F06:
	cmp r0, #0
	bne _081E2F24
	bl FUN_08049f5c
	bl Marquee_Clear
	movs r2, #1
	ldr r0, _081E2F20 @ =0x00001610
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _081E32C8
	.align 2, 0
_081E2F20: .4byte 0x00001610
_081E2F24:
	ldr r1, _081E2F60 @ =0x00001616
	adds r4, r5, r1
	ldrb r0, [r4]
	cmp r0, #0x16
	beq _081E2F36
	cmp r0, #0x13
	beq _081E2F36
	cmp r0, #0xa
	bne _081E2F6C
_081E2F36:
	ldr r2, _081E2F64 @ =0x00001617
	adds r4, r5, r2
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0xa
	bne _081E2F44
	b _081E32C8
_081E2F44:
	bl Marquee_Clear
	ldr r1, _081E2F68 @ =0x000015F0
	adds r0, r5, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #0xa
	bl Textbox_LookupString
	bl Marquee_SetText
	movs r0, #0xa
	b _081E32C6
	.align 2, 0
_081E2F60: .4byte 0x00001616
_081E2F64: .4byte 0x00001617
_081E2F68: .4byte 0x000015F0
_081E2F6C:
	bl LinkShopManager_IsBusy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E2F8C
	ldrb r0, [r4]
	cmp r0, #2
	beq _081E2F8C
	cmp r0, #0x15
	beq _081E2F8C
	cmp r0, #8
	beq _081E2F8C
	cmp r0, #0x1d
	beq _081E2F8C
	cmp r0, #5
	bne _081E2FC0
_081E2F8C:
	ldr r2, _081E2FB8 @ =0x00001617
	adds r4, r5, r2
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #7
	bne _081E2F9A
	b _081E32C8
_081E2F9A:
	bl Marquee_Clear
	ldr r1, _081E2FBC @ =0x000015F0
	adds r0, r5, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #7
	bl Textbox_LookupString
	bl Marquee_SetText
	movs r0, #7
	b _081E32C6
	.align 2, 0
_081E2FB8: .4byte 0x00001617
_081E2FBC: .4byte 0x000015F0
_081E2FC0:
	bl LinkShopManager_IsParent
	cmp r0, #0
	bne _081E2FCA
	b _081E3154
_081E2FCA:
	ldrb r0, [r4]
	cmp r0, #0
	beq _081E2FD2
	b _081E3184
_081E2FD2:
	ldr r2, _081E3018 @ =0x00001615
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _081E309C
	ldr r1, _081E301C @ =0x00000BB5
	adds r0, r5, r1
	ldrb r0, [r0]
	ldr r2, _081E3020 @ =0x00000BB4
	adds r1, r5, r2
	ldrb r1, [r1]
	subs r0, r0, r1
	cmp r0, #0
	bgt _081E302C
	ldr r0, _081E3024 @ =0x00001617
	adds r4, r5, r0
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #5
	bne _081E2FFC
	b _081E32C8
_081E2FFC:
	bl Marquee_Clear
	ldr r1, _081E3028 @ =0x000015F0
	adds r0, r5, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #5
	bl Textbox_LookupString
	bl Marquee_SetText
	movs r0, #5
	b _081E3182
	.align 2, 0
_081E3018: .4byte 0x00001615
_081E301C: .4byte 0x00000BB5
_081E3020: .4byte 0x00000BB4
_081E3024: .4byte 0x00001617
_081E3028: .4byte 0x000015F0
_081E302C:
	bl CountSellableWeapons
	cmp r0, #0
	bgt _081E3068
	ldr r2, _081E3060 @ =0x00001617
	adds r4, r5, r2
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0x14
	bne _081E3042
	b _081E32C8
_081E3042:
	bl Marquee_Clear
	ldr r1, _081E3064 @ =0x000015F0
	adds r0, r5, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #0x14
	bl Textbox_LookupString
	bl Marquee_SetText
	movs r0, #0x14
	b _081E3182
	.align 2, 0
_081E3060: .4byte 0x00001617
_081E3064: .4byte 0x000015F0
_081E3068:
	ldr r2, _081E3094 @ =0x00001617
	adds r4, r5, r2
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #3
	bne _081E3076
	b _081E32C8
_081E3076:
	bl Marquee_Clear
	ldr r1, _081E3098 @ =0x000015F0
	adds r0, r5, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #3
	bl Textbox_LookupString
	bl Marquee_SetText
	movs r0, #3
	b _081E3182
	.align 2, 0
_081E3094: .4byte 0x00001617
_081E3098: .4byte 0x000015F0
_081E309C:
	bl CountSellableOrEmptySlots
	adds r4, r0, #0
	bl CountSellableWeapons
	subs r4, r4, r0
	cmp r4, #0
	bgt _081E30E0
	ldr r2, _081E30D8 @ =0x00001617
	adds r4, r5, r2
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #6
	bne _081E30BA
	b _081E32C8
_081E30BA:
	bl Marquee_Clear
	ldr r1, _081E30DC @ =0x000015F0
	adds r0, r5, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #6
	bl Textbox_LookupString
	bl Marquee_SetText
	movs r0, #6
	b _081E3182
	.align 2, 0
_081E30D8: .4byte 0x00001617
_081E30DC: .4byte 0x000015F0
_081E30E0:
	ldr r2, _081E3114 @ =0x00000BB4
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _081E3120
	ldr r0, _081E3118 @ =0x00001617
	adds r4, r5, r0
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0x15
	bne _081E30F8
	b _081E32C8
_081E30F8:
	bl Marquee_Clear
	ldr r1, _081E311C @ =0x000015F0
	adds r0, r5, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #0x15
	bl Textbox_LookupString
	bl Marquee_SetText
	movs r0, #0x15
	b _081E3182
	.align 2, 0
_081E3114: .4byte 0x00000BB4
_081E3118: .4byte 0x00001617
_081E311C: .4byte 0x000015F0
_081E3120:
	ldr r2, _081E314C @ =0x00001617
	adds r4, r5, r2
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #4
	bne _081E312E
	b _081E32C8
_081E312E:
	bl Marquee_Clear
	ldr r1, _081E3150 @ =0x000015F0
	adds r0, r5, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #4
	bl Textbox_LookupString
	bl Marquee_SetText
	movs r0, #4
	b _081E3182
	.align 2, 0
_081E314C: .4byte 0x00001617
_081E3150: .4byte 0x000015F0
_081E3154:
	ldrb r0, [r4]
	cmp r0, #1
	bne _081E3184
	ldr r2, _081E31BC @ =0x00001617
	adds r4, r5, r2
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #2
	bne _081E3168
	b _081E32C8
_081E3168:
	bl Marquee_Clear
	ldr r1, _081E31C0 @ =0x000015F0
	adds r0, r5, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #2
	bl Textbox_LookupString
	bl Marquee_SetText
	movs r0, #2
_081E3182:
	strb r0, [r4]
_081E3184:
	ldr r2, _081E31C4 @ =0x00001616
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0xa
	beq _081E3192
	cmp r0, #0xd
	bne _081E31C8
_081E3192:
	ldr r0, _081E31BC @ =0x00001617
	adds r4, r5, r0
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0xa
	bne _081E31A0
	b _081E32C8
_081E31A0:
	bl Marquee_Clear
	ldr r1, _081E31C0 @ =0x000015F0
	adds r0, r5, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #0xa
	bl Textbox_LookupString
	bl Marquee_SetText
	movs r0, #0xa
	b _081E32C6
	.align 2, 0
_081E31BC: .4byte 0x00001617
_081E31C0: .4byte 0x000015F0
_081E31C4: .4byte 0x00001616
_081E31C8:
	cmp r0, #3
	bne _081E31E4
	ldr r2, _081E31DC @ =0x00001617
	adds r6, r5, r2
	movs r1, #0
	ldrsb r1, [r6, r1]
	ldr r0, _081E31E0 @ =0x0000161A
	adds r4, r5, r0
	b _081E3230
	.align 2, 0
_081E31DC: .4byte 0x00001617
_081E31E0: .4byte 0x0000161A
_081E31E4:
	cmp r0, #4
	bne _081E324C
	ldr r1, _081E321C @ =0x0000161A
	adds r4, r5, r1
	ldrb r0, [r4]
	cmp r0, #0x11
	bne _081E3228
	ldr r2, _081E3220 @ =0x00001617
	adds r4, r5, r2
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0xf
	beq _081E32C8
	bl Marquee_Clear
	ldr r1, _081E3224 @ =0x000015F0
	adds r0, r5, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #0xf
	bl Textbox_LookupString
	bl Marquee_SetText
	movs r0, #0xf
	b _081E32C6
	.align 2, 0
_081E321C: .4byte 0x0000161A
_081E3220: .4byte 0x00001617
_081E3224: .4byte 0x000015F0
_081E3228:
	ldr r2, _081E3248 @ =0x00001617
	adds r6, r5, r2
	movs r1, #0
	ldrsb r1, [r6, r1]
_081E3230:
	ldrb r0, [r4]
	adds r0, #0x19
	cmp r1, r0
	beq _081E32C8
	adds r0, r5, #0
	bl FUN_081e4544
	ldrb r0, [r4]
	adds r0, #0x19
	strb r0, [r6]
	b _081E32C8
	.align 2, 0
_081E3248: .4byte 0x00001617
_081E324C:
	cmp r0, #7
	bne _081E32C8
	ldr r0, _081E3290 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x91
	lsls r1, r1, #4
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r2, _081E3294 @ =0x000015E4
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r1, r0
	blt _081E32A0
	ldr r0, _081E3298 @ =0x00001617
	adds r4, r5, r0
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0x10
	beq _081E32C8
	bl Marquee_Clear
	ldr r1, _081E329C @ =0x000015F0
	adds r0, r5, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #0x10
	bl Textbox_LookupString
	bl Marquee_SetText
	movs r0, #0x10
	b _081E32C6
	.align 2, 0
_081E3290: .4byte 0x030046A0
_081E3294: .4byte 0x000015E4
_081E3298: .4byte 0x00001617
_081E329C: .4byte 0x000015F0
_081E32A0:
	ldr r2, _081E32D0 @ =0x00001617
	adds r4, r5, r2
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0x11
	beq _081E32C8
	bl Marquee_Clear
	ldr r1, _081E32D4 @ =0x000015F0
	adds r0, r5, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #0x11
	bl Textbox_LookupString
	bl Marquee_SetText
	movs r0, #0x11
_081E32C6:
	strb r0, [r4]
_081E32C8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081E32D0: .4byte 0x00001617
_081E32D4: .4byte 0x000015F0
